'use strict';

var Core$ReactNavigation = require("./Core.bs.js");
var MaterialTopTabs = require("@react-navigation/material-top-tabs");

var MaterialTopTabNavigationProp = Core$ReactNavigation.NavigationScreenProp;

function Make(M) {
  var M$1 = { };
  var include = Core$ReactNavigation.NavigationScreenProp(M$1);
  var Navigation = include;
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
          $$Screen: $$Screen,
          $$Navigator: $$Navigator
        };
}

exports.MaterialTopTabNavigationProp = MaterialTopTabNavigationProp;
exports.Make = Make;
/* @react-navigation/material-top-tabs Not a pure module */
