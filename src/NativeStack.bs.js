'use strict';

var NativeStack = require("@react-navigation/native-stack");

function Make($star) {
  var internal = NativeStack.createNativeStackNavigator();
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
/* @react-navigation/native-stack Not a pure module */
