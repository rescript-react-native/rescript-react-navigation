'use strict';

var Interop = require("./Interop");
var MaterialBottomTabs = require("@react-navigation/material-bottom-tabs");

var TabBarBadge = {};

function adaptNavigatorModule(prim) {
  return Interop.adaptNavigatorModule(prim);
}

function Make($star) {
  return Interop.adaptNavigatorModule(MaterialBottomTabs.createMaterialBottomTabNavigator());
}

var Navigation = {};

exports.TabBarBadge = TabBarBadge;
exports.adaptNavigatorModule = adaptNavigatorModule;
exports.Make = Make;
exports.Navigation = Navigation;
/* ./Interop Not a pure module */
