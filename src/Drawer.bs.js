'use strict';

var Core$ReactNavigation = require("./Core.bs.js");
var Drawer = require("@react-navigation/drawer");

function DrawerNavigationProp(M) {
  var include = Core$ReactNavigation.NavigationScreenProp(M);
  return {
          navigateByKey: include.navigateByKey,
          navigateByName: include.navigateByName
        };
}

function Make(M) {
  var M$1 = { };
  var include = Core$ReactNavigation.NavigationScreenProp(M$1);
  var Navigation_navigateByKey = include.navigateByKey;
  var Navigation_navigateByName = include.navigateByName;
  var Navigation = {
    navigateByKey: Navigation_navigateByKey,
    navigateByName: Navigation_navigateByName
  };
  var stack = Drawer.createDrawerNavigator();
  var make = stack.Screen;
  var $$Screen = {
    make: make
  };
  var make$1 = stack.Navigator;
  var $$Navigator = {
    make: make$1
  };
  return {
          Navigation: Navigation,
          stack: stack,
          Screen: $$Screen,
          Navigator: $$Navigator
        };
}

exports.DrawerNavigationProp = DrawerNavigationProp;
exports.Make = Make;
/* @react-navigation/drawer Not a pure module */
