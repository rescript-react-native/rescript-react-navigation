'use strict';

var Interop = require("./Interop");
var NativeStack = require("@react-navigation/native-stack");

function Make($star) {
  return Interop.adaptNavigatorModule(NativeStack.createNativeStackNavigator());
}

var Navigation = {};

exports.Make = Make;
exports.Navigation = Navigation;
/* ./Interop Not a pure module */
