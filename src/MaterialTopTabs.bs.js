'use strict';

var Interop = require("./Interop");
var MaterialTopTabs = require("@react-navigation/material-top-tabs");

function Make($star) {
  return Interop.adaptNavigatorModule(MaterialTopTabs.createMaterialTopTabNavigator());
}

var $$Navigation = {};

exports.Make = Make;
exports.$$Navigation = $$Navigation;
/* ./Interop Not a pure module */
