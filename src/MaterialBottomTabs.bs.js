'use strict';

var Interop = require("./Interop");
var Core$ReactNavigation = require("./Core.bs.js");
var MaterialBottomTabs = require("@react-navigation/material-bottom-tabs");

var MaterialBottomTabNavigationProp = Core$ReactNavigation.NavigationScreenProp;

function Make(M) {
  var M$1 = { };
  var include = Core$ReactNavigation.NavigationScreenProp(M$1);
  var Navigation = include;
  var t = function (prim) {
    return Interop.identity(prim[1]);
  };
  var $$boolean = function (x) {
    return Interop.identity(x);
  };
  var number = function (x) {
    return Interop.identity(x);
  };
  var string = function (x) {
    return Interop.identity(x);
  };
  var TabBarBadge = {
    t: t,
    $$boolean: $$boolean,
    number: number,
    string: string
  };
  var stack = MaterialBottomTabs.createMaterialBottomTabNavigator();
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
          TabBarBadge: TabBarBadge,
          stack: stack,
          $$Screen: $$Screen,
          $$Navigator: $$Navigator
        };
}

exports.MaterialBottomTabNavigationProp = MaterialBottomTabNavigationProp;
exports.Make = Make;
/* ./Interop Not a pure module */
