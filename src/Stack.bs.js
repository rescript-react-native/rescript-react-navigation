'use strict';

var Stack = require("@react-navigation/stack");

var TransitionSpec = {};

function Make($star) {
  var internal = Stack.createStackNavigator();
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

var TransitionSpecs = {};

var CardStyleInterpolators = {};

var HeaderStyleInterpolators = {};

var TransitionPresets = {};

exports.TransitionSpec = TransitionSpec;
exports.Make = Make;
exports.$$Navigation = $$Navigation;
exports.TransitionSpecs = TransitionSpecs;
exports.CardStyleInterpolators = CardStyleInterpolators;
exports.HeaderStyleInterpolators = HeaderStyleInterpolators;
exports.TransitionPresets = TransitionPresets;
/* @react-navigation/stack Not a pure module */
