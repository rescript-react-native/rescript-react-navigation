'use strict';

var Core$ReactNavigation = require("./Core.bs.js");
var BottomTabs = require("@react-navigation/bottom-tabs");

var BottomTabNavigationProp = Core$ReactNavigation.NavigationScreenProp;

function Make(M) {
  var M$1 = {};
  var include = Core$ReactNavigation.NavigationScreenProp(M$1);
  var Navigation = include;
  var bottomTabs = BottomTabs.createBottomTabNavigator();
  var make = bottomTabs.Screen;
  var $$Screen = {
    make: make
  };
  var make$1 = bottomTabs.Screen;
  var ScreenWithCallback = {
    make: make$1
  };
  var make$2 = bottomTabs.Navigator;
  var $$Navigator = {
    make: make$2
  };
  var make$3 = bottomTabs.Group;
  var Group = {
    make: make$3
  };
  return {
          Navigation: Navigation,
          bottomTabs: bottomTabs,
          $$Screen: $$Screen,
          ScreenWithCallback: ScreenWithCallback,
          $$Navigator: $$Navigator,
          Group: Group
        };
}

exports.BottomTabNavigationProp = BottomTabNavigationProp;
exports.Make = Make;
/* @react-navigation/bottom-tabs Not a pure module */
