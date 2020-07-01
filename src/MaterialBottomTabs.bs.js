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
  var materialBottomTabs = MaterialBottomTabs.createMaterialBottomTabNavigator();
  var make = materialBottomTabs.Screen;
  var $$Screen = {
    make: make
  };
  var make$1 = materialBottomTabs.Screen;
  var ScreenWithCallback = {
    make: make$1
  };
  var make$2 = materialBottomTabs.Navigator;
  var $$Navigator = {
    make: make$2
  };
  return {
          Navigation: Navigation,
          TabBarBadge: TabBarBadge,
          materialBottomTabs: materialBottomTabs,
          $$Screen: $$Screen,
          ScreenWithCallback: ScreenWithCallback,
          $$Navigator: $$Navigator
        };
}

exports.MaterialBottomTabNavigationProp = MaterialBottomTabNavigationProp;
exports.Make = Make;
/* ./Interop Not a pure module */
