'use strict';

var Core$ReactNavigation = require("./Core.bs.js");
var NativeStack = require("@react-navigation/native-stack");

var NativeStackNavigationScreenProp = Core$ReactNavigation.NavigationScreenProp;

function Make(M) {
  var M$1 = {};
  var include = Core$ReactNavigation.NavigationScreenProp(M$1);
  var Navigation = include;
  var stack = NativeStack.createNativeStackNavigator();
  var make = stack.Screen;
  var ScreenWithCallback = {
    make: make
  };
  var make$1 = stack.Screen;
  var $$Screen = {
    make: make$1
  };
  var make$2 = stack.Navigator;
  var $$Navigator = {
    make: make$2
  };
  var make$3 = stack.Group;
  var Group = {
    make: make$3
  };
  return {
          Navigation: Navigation,
          stack: stack,
          ScreenWithCallback: ScreenWithCallback,
          $$Screen: $$Screen,
          $$Navigator: $$Navigator,
          Group: Group
        };
}

exports.NativeStackNavigationScreenProp = NativeStackNavigationScreenProp;
exports.Make = Make;
/* @react-navigation/native-stack Not a pure module */
