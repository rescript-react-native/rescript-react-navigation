'use strict';

var Core$ReactNavigation = require("./Core.bs.js");
var MaterialTopTabs = require("@react-navigation/material-top-tabs");

var MaterialTopTabNavigationProp = Core$ReactNavigation.NavigationScreenProp;

function Make(M) {
  var M$1 = {};
  var include = Core$ReactNavigation.NavigationScreenProp(M$1);
  var Navigation = include;
  var materialTopTabs = MaterialTopTabs.createMaterialTopTabNavigator();
  var make = materialTopTabs.Screen;
  var $$Screen = {
    make: make
  };
  var make$1 = materialTopTabs.Screen;
  var ScreenWithCallback = {
    make: make$1
  };
  var make$2 = materialTopTabs.Navigator;
  var $$Navigator = {
    make: make$2
  };
  var make$3 = materialTopTabs.Group;
  var Group = {
    make: make$3
  };
  var MaterialTopTabBar = {};
  return {
          Navigation: Navigation,
          materialTopTabs: materialTopTabs,
          $$Screen: $$Screen,
          ScreenWithCallback: ScreenWithCallback,
          $$Navigator: $$Navigator,
          Group: Group,
          MaterialTopTabBar: MaterialTopTabBar
        };
}

exports.MaterialTopTabNavigationProp = MaterialTopTabNavigationProp;
exports.Make = Make;
/* @react-navigation/material-top-tabs Not a pure module */
