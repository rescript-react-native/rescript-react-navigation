'use strict';

var Core$ReactNavigation = require("./Core.bs.js");
var MaterialTopTabs = require("@react-navigation/material-top-tabs");

function MaterialTopTabNavigationProp(M) {
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
  var stack = MaterialTopTabs.createMaterialTopTabNavigator();
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

exports.MaterialTopTabNavigationProp = MaterialTopTabNavigationProp;
exports.Make = Make;
/* @react-navigation/material-top-tabs Not a pure module */
