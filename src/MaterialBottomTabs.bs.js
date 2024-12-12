'use strict';

var Interop = require("./Interop");
var MaterialBottomTabs = require("@react-navigation/material-bottom-tabs");

var TabBarBadge = {};

function Make($star) {
  return Interop.adaptNavigatorModule(MaterialBottomTabs.createMaterialBottomTabNavigator());
}

var $$Navigation = {};

exports.TabBarBadge = TabBarBadge;
exports.Make = Make;
exports.$$Navigation = $$Navigation;
/* ./Interop Not a pure module */
