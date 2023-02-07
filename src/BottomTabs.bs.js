'use strict';

var Interop = require("./Interop");
var BottomTabs = require("@react-navigation/bottom-tabs");

var TabBarBadge = {};

function Make($star) {
  return Interop.adaptNavigatorModule(BottomTabs.createBottomTabNavigator());
}

var Navigation = {};

exports.TabBarBadge = TabBarBadge;
exports.Make = Make;
exports.Navigation = Navigation;
/* ./Interop Not a pure module */
