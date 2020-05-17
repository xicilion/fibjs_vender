#!/bin/js

var fs = require("fs");
var hash = require("hash");
var path = require("path");

var venderRootDir = path.resolve(__dirname, '../');
var thisPrjBase = process.cwd();
var addonConfigJsonPath = path.resolve(thisPrjBase, 'jssdk.config.json');
var addonConfig = { ProjectType: undefined };
try { addonConfig = JSON.parse(fs.readTextFile(addonConfigJsonPath)); } catch (e) { }

var fibjsProjType = addonConfig.ProjectType || 'InternalLibrary';
if (path.resolve(path.dirname(path.dirname(thisPrjBase))) === venderRootDir) fibjsProjType = 'InternalLibraryTest';

var isSubProj = false
var rootRelRef = ''
var includeRelRef = [].join(';')
var additionalLibs = [].join(';')
var prjName = path.basename(thisPrjBase);
var platformToolset = 'LLVM_FIBJS_v141';
var ConfigurationType;

switch (fibjsProjType) {
    default:
    case 'InternalLibrary':
        rootRelRef = `$(ProjectDir)\\..`
        includeRelRef = '$(ProjectDir)\\..'

        ConfigurationType = 'StaticLibrary'
        break;
    case 'InternalLibraryTest':
        rootRelRef = `$(ProjectDir)\\..\\..`
        includeRelRef = '$(ProjectDir)\\..\\..;$(ProjectDir)\\..\\include'

        ConfigurationType = 'Application'
        prjName = `${path.basename(path.dirname(thisPrjBase))}_test`
        isSubProj = true;
        break;
    case 'Addon':
        var addonRelVenderRoot = `${path.normalize(path.relative(thisPrjBase, venderRootDir))}`
        rootRelRef = `$(ProjectDir)\\${addonRelVenderRoot}`
        includeRelRef = `$(ProjectDir)\\${addonRelVenderRoot};$(ProjectDir)\\${addonRelVenderRoot}\\v8\\include`

        ConfigurationType = 'DynamicLibrary'
        break;
}

var oPrjName = process.env.PROJECT_NAME || prjName;

console.info(`[vender::vsmake] generate project '${prjName}': {fibjsProjType: ${fibjsProjType}; ConfigurationType: ${ConfigurationType}}`)

var Includes = {};
var Compiles = {};
var filters = [];

var dis_archs = {
    arm: 1,
    arm64: 1,
    mips: 1,
    mips64: 1
};

function do_folder(p, base) {
    var dir = fs.readdir(path.join(thisPrjBase, p.replace(/\\/g, '/')));

    filters.push(base);

    dir.forEach(function (name) {
        var f = fs.stat(path.join(thisPrjBase, p.replace(/\\/g, '/') + '/' + name));
        if (f.isDirectory()) {
            if (!dis_archs[name])
                do_folder(p + '\\' + name, base + '\\' + name);
        } else {
            var len = name.length;
            var bInc = name.substr(len - 2, 2) === '.h';
            var bCc = name.substr(len - 3, 3) === '.cc' || name.substr(len - 4, 4) === '.cpp' || name.substr(len - 2, 2) === '.c';

            if (bInc)
                Includes[p + '\\' + name] = base;
            else if (bCc)
                Compiles[p + '\\' + name] = base;
        }
    });
}

try {
    do_folder("include", "Header Files");
} catch (e) { }

try {
    do_folder(prjName, "Header Files");
} catch (e) { }

do_folder("src", "Source Files");

var projTpl = fs.exists(path.join(thisPrjBase, 'tools/proj.txt')) ? path.join(thisPrjBase, 'tools/proj.txt') : path.join(venderRootDir, 'tools/tools/proj.txt')
var filterTpl = fs.exists(path.join(thisPrjBase, 'tools/filter.txt')) ? path.join(thisPrjBase, 'tools/filter.txt') : path.join(venderRootDir, 'tools/tools/filter.txt')

var proj = fs.readTextFile(projTpl);
var filter = fs.readTextFile(filterTpl);

var txts, f, s, h;

txts = [];
for (f in Includes) {
    txts.push('    <ClInclude Include="' + f + '" />');
}
txts.sort();

proj = proj.replace(/__PROJECT_NAME__/g, oPrjName)
proj = proj.replace(/__FIBJS_PROJECT_TYPE__/g, fibjsProjType)
proj = proj.replace(/__VENDER_ROOT__/g, venderRootDir)
proj = proj.replace(/__PROJECT_INCLUDE_RELREF__/g, includeRelRef)
proj = proj.replace(/__PROJECT_CONFIGURATION_TYPE__/g, ConfigurationType)
proj = proj.replace(/__PROJECT_LIB__/g, additionalLibs)
proj = proj.replace(/__PlatformToolset__/g, platformToolset)

proj = proj.replace('<ClIncludes />', txts.join('\r\n'));

txts = [];
for (f in Compiles) {
    txts.push('    <ClCompile Include="' + f + '" />');
}
txts.sort();
proj = proj.replace('<ClCompiles />', txts.join('\r\n'));


fs.writeFile(path.join(thisPrjBase, oPrjName + ".vcxproj"), proj);

filters.sort();

txts = [];
filters.forEach(function (f) {
    h = hash.md5(f).digest().hex();

    s = '    <Filter Include="' + f + '">\r\n      <UniqueIdentifier>{';
    s += h.substr(0, 8) + '-' + h.substr(8, 4) + '-' + h.substr(12, 4) + '-' + h.substr(16, 4) + '-' + h.substr(20);
    s += '}</UniqueIdentifier>\r\n    </Filter>';

    txts.push(s);
});
filter = filter.replace('<Filters />', txts.join('\r\n'));

txts = [];
for (f in Includes) {
    txts.push('    <ClInclude Include="' + f + '">\r\n      <Filter>' + Includes[f] + '</Filter>\r\n    </ClInclude>');
}
txts.sort();
filter = filter.replace('<ClIncludes />', txts.join('\r\n'));

txts = [];
for (f in Compiles) {
    txts.push('    <ClCompile Include="' + f + '">\r\n      <Filter>' + Compiles[f] + '</Filter>\r\n    </ClCompile>');
}
txts.sort();
filter = filter.replace('<ClCompiles />', txts.join('\r\n'));

fs.writeFile(path.join(thisPrjBase, oPrjName + ".vcxproj.filters"), filter);