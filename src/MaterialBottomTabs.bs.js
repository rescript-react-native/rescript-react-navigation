'use strict';

var Interop = require("./Interop");
var ReactNavigation = require("react-native-paper/react-navigation");

var TabBarBadge = {};

function Make($star) {
  return Interop.adaptNavigatorModule(ReactNavigation.createMaterialBottomTabNavigator());
}

var $$Navigation = {};

exports.TabBarBadge = TabBarBadge;
exports.Make = Make;
exports.$$Navigation = $$Navigation;
/* ./Interop Not a pure module */
