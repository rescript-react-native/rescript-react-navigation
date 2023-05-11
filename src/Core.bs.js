


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

export {
  Params ,
  backBehaviorToJs ,
  backBehaviorFromJs ,
  NavigationEvent ,
  Navigation ,
  
}
/* No side effect */
