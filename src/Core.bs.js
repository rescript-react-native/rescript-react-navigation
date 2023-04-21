'use strict';


var Params = {};

var _map = {"firstRoute":"firstRoute","initialRoute":"initialRoute","order":"order","history":"history","none":"none"};

function backBehaviorToJs(param) {
  return param;
}

function backBehaviorFromJs(param) {
  return _map[param];
}

var NavigationEvent = {};

var Navigation = {};

exports.Params = Params;
exports.backBehaviorToJs = backBehaviorToJs;
exports.backBehaviorFromJs = backBehaviorFromJs;
exports.NavigationEvent = NavigationEvent;
exports.Navigation = Navigation;
/* No side effect */
