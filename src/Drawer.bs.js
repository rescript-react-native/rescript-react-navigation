'use strict';

var Interop = require("./Interop");
var Drawer = require("@react-navigation/drawer");

function Make($star) {
  return Interop.adaptNavigatorModule(Drawer.createDrawerNavigator());
}

var $$Navigation = {};

exports.Make = Make;
exports.$$Navigation = $$Navigation;
/* ./Interop Not a pure module */
