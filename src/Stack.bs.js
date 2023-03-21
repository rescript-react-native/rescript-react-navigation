'use strict';

var Interop = require("./Interop");
var Stack = require("@react-navigation/stack");

var TransitionSpec = {};

function Make($star) {
  return Interop.adaptNavigatorModule(Stack.createStackNavigator());
}

var Navigation = {};

var TransitionSpecs = {};

var CardStyleInterpolators = {};

var HeaderStyleInterpolators = {};

var TransitionPresets = {};

exports.TransitionSpec = TransitionSpec;
exports.Make = Make;
exports.Navigation = Navigation;
exports.TransitionSpecs = TransitionSpecs;
exports.CardStyleInterpolators = CardStyleInterpolators;
exports.HeaderStyleInterpolators = HeaderStyleInterpolators;
exports.TransitionPresets = TransitionPresets;
/* ./Interop Not a pure module */
