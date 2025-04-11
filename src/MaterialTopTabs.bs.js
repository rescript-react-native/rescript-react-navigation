'use strict';

var MaterialTopTabs = require("@react-navigation/material-top-tabs");

function Make($star) {
  var internal = MaterialTopTabs.createMaterialTopTabNavigator();
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

exports.Make = Make;
exports.$$Navigation = $$Navigation;
/* @react-navigation/material-top-tabs Not a pure module */
