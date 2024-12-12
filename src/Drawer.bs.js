'use strict';

var Interop = require("./Interop");
var Drawer = require("@react-navigation/drawer");

function Make($star) {
  return Interop.adaptNavigatorModule(Drawer.createDrawerNavigator());
}

var $$Navigation = {};

var DrawerItemList = {};

exports.Make = Make;
exports.$$Navigation = $$Navigation;
exports.DrawerItemList = DrawerItemList;
/* ./Interop Not a pure module */
