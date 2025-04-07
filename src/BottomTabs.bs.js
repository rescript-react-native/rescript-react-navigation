'use strict';

var BottomTabs = require("@react-navigation/bottom-tabs");

var TabBarBadge = {};

function Make($star) {
  var internal = BottomTabs.createBottomTabNavigator();
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

exports.TabBarBadge = TabBarBadge;
exports.Make = Make;
exports.$$Navigation = $$Navigation;
/* @react-navigation/bottom-tabs Not a pure module */
