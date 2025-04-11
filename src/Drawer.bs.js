'use strict';

var Drawer = require("@react-navigation/drawer");

function Make($star) {
  var internal = Drawer.createDrawerNavigator();
  var make = internal.Navigator;
  var $$Navigator = {
    make: make
  };
  var make$1 = internal.Screen;
  var $$Screen = {
    make: make$1
  };
  var make$2 = internal.Group;
  var Group = {
    make: make$2
  };
  return {
          $$Navigator: $$Navigator,
          $$Screen: $$Screen,
          Group: Group
        };
}

var $$Navigation = {};

var DrawerItemList = {};

exports.Make = Make;
exports.$$Navigation = $$Navigation;
exports.DrawerItemList = DrawerItemList;
/* @react-navigation/drawer Not a pure module */
