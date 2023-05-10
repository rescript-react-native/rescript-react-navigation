'use strict';

var Interop = require("./Interop");
var MaterialTopTabs = require("@react-navigation/material-top-tabs");

var _map = {"top":"top","bottom":"bottom"};

function tabBarPositionToJs(param) {
  return param;
}

function tabBarPositionFromJs(param) {
  return _map[param];
}

var _map$1 = {"auto":"auto","on_drag":"on-drag","none":"none"};

var _revMap = {"auto":"auto","on-drag":"on_drag","none":"none"};

function keyboardDismissModeToJs(param) {
  return _map$1[param];
}

function keyboardDismissModeFromJs(param) {
  return _revMap[param];
}

function adaptNavigatorModule(prim) {
  return Interop.adaptNavigatorModule(prim);
}

function Make($star) {
  return Interop.adaptNavigatorModule(MaterialTopTabs.createMaterialTopTabNavigator());
}

var Navigation = {};

exports.tabBarPositionToJs = tabBarPositionToJs;
exports.tabBarPositionFromJs = tabBarPositionFromJs;
exports.keyboardDismissModeToJs = keyboardDismissModeToJs;
exports.keyboardDismissModeFromJs = keyboardDismissModeFromJs;
exports.adaptNavigatorModule = adaptNavigatorModule;
exports.Make = Make;
exports.Navigation = Navigation;
/* ./Interop Not a pure module */
