

import * as Interop from "./Interop";
import * as Stack from "@react-navigation/stack";

var _map = {"card":"card","modal":"modal","transparentModal":"transparentModal"};

function presentationToJs(param) {
  return param;
}

function presentationFromJs(param) {
  return _map[param];
}

var _map$1 = {"push":"push","pop":"pop"};

function animationTypeForReplaceToJs(param) {
  return param;
}

function animationTypeForReplaceFromJs(param) {
  return _map$1[param];
}

var _map$2 = {"horizontal":"horizontal","horizontal_inverted":"horizontal-inverted","vertical_inverted":"vertical-inverted"};

var _revMap = {"horizontal":"horizontal","horizontal-inverted":"horizontal_inverted","vertical-inverted":"vertical_inverted"};

function gestureDirectionToJs(param) {
  return _map$2[param];
}

function gestureDirectionFromJs(param) {
  return _revMap[param];
}

var TransitionSpec = {};

function adaptNavigatorModule(prim) {
  return Interop.adaptNavigatorModule(prim);
}

function Make($star) {
  return Interop.adaptNavigatorModule(Stack.createStackNavigator());
}

var Navigation = {};

var TransitionSpecs = {};

var CardStyleInterpolators = {};

var HeaderStyleInterpolators = {};

var TransitionPresets = {};

export {
  presentationToJs ,
  presentationFromJs ,
  animationTypeForReplaceToJs ,
  animationTypeForReplaceFromJs ,
  gestureDirectionToJs ,
  gestureDirectionFromJs ,
  TransitionSpec ,
  adaptNavigatorModule ,
  Make ,
  Navigation ,
  TransitionSpecs ,
  CardStyleInterpolators ,
  HeaderStyleInterpolators ,
  TransitionPresets ,
  
}
/* ./Interop Not a pure module */
