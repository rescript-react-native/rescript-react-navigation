'use strict';

var Interop = require("./Interop");
var NativeStack = require("@react-navigation/native-stack");

var _map = {"default":"default","fade":"fade","fade_from_bottom":"fade_from_bottom","flip":"flip","simple_push":"simple_push","slide_from_bottom":"slide_from_bottom","slide_from_right":"slide_from_right","slide_from_left":"slide_from_left","none":"none"};

function animationToJs(param) {
  return param;
}

function animationFromJs(param) {
  return _map[param];
}

var _map$1 = {"push":"push","pop":"pop"};

function animationTypeForReplaceToJs(param) {
  return param;
}

function animationTypeForReplaceFromJs(param) {
  return _map$1[param];
}

var _map$2 = {"extraLight":"extraLight","light":"light","dark":"dark","regular":"regular","prominent":"prominent","systemUltraThinMaterial":"systemUltraThinMaterial","systemThinMaterial":"systemThinMaterial","systemMaterial":"systemMaterial","systemThickMaterial":"systemThickMaterial","systemChromeMaterial":"systemChromeMaterial","systemUltraThinMaterialLight":"systemUltraThinMaterialLight","systemThinMaterialLight":"systemThinMaterialLight","systemMaterialLight":"systemMaterialLight","systemThickMaterialLight":"systemThickMaterialLight","systemChromeMaterialLight":"systemChromeMaterialLight","systemUltraThinMaterialDark":"systemUltraThinMaterialDark","systemThinMaterialDark":"systemThinMaterialDark","systemMaterialDark":"systemMaterialDark","systemThickMaterialDark":"systemThickMaterialDark","systemChromeMaterialDark":"systemChromeMaterialDark"};

function blurEffectToJs(param) {
  return param;
}

function blurEffectFromJs(param) {
  return _map$2[param];
}

var _map$3 = {"card":"card","modal":"modal","transparentModal":"transparentModal","containedModal":"containedModal","containedTransparentModal":"containedTransparentModal","fullScreenModal":"fullScreenModal","formSheet":"formSheet"};

function presentationToJs(param) {
  return param;
}

function presentationFromJs(param) {
  return _map$3[param];
}

var _map$4 = {"auto":"auto","inverted":"inverted","light":"light","dark":"dark"};

function statusBarStyleToJs(param) {
  return param;
}

function statusBarStyleFromJs(param) {
  return _map$4[param];
}

var _map$5 = {"fade":"fade","none":"none","slide":"slide"};

function statusBarAnimationToJs(param) {
  return param;
}

function statusBarAnimationFromJs(param) {
  return _map$5[param];
}

var _map$6 = {"default":"default","all":"all","portrait":"portrait","portrait_up":"portrait_up","portrait_down":"portrait_down","landscape":"landscape","landscape_left":"landscape_left","landscape_right":"landscape_right"};

function orientationToJs(param) {
  return param;
}

function orientationFromJs(param) {
  return _map$6[param];
}

function adaptNavigatorModule(prim) {
  return Interop.adaptNavigatorModule(prim);
}

function Make($star) {
  return Interop.adaptNavigatorModule(NativeStack.createNativeStackNavigator());
}

var Navigation = {};

exports.animationToJs = animationToJs;
exports.animationFromJs = animationFromJs;
exports.animationTypeForReplaceToJs = animationTypeForReplaceToJs;
exports.animationTypeForReplaceFromJs = animationTypeForReplaceFromJs;
exports.blurEffectToJs = blurEffectToJs;
exports.blurEffectFromJs = blurEffectFromJs;
exports.presentationToJs = presentationToJs;
exports.presentationFromJs = presentationFromJs;
exports.statusBarStyleToJs = statusBarStyleToJs;
exports.statusBarStyleFromJs = statusBarStyleFromJs;
exports.statusBarAnimationToJs = statusBarAnimationToJs;
exports.statusBarAnimationFromJs = statusBarAnimationFromJs;
exports.orientationToJs = orientationToJs;
exports.orientationFromJs = orientationFromJs;
exports.adaptNavigatorModule = adaptNavigatorModule;
exports.Make = Make;
exports.Navigation = Navigation;
/* ./Interop Not a pure module */
