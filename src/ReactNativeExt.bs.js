'use strict';


var _map = {"normal":"normal","bold":"bold","_100":"100","_200":"200","_300":"300","_400":"400","_500":"500","_600":"600","_700":"700","_800":"800","_900":"900"};

var _revMap = {"normal":"normal","bold":"bold","100":"_100","200":"_200","300":"_300","400":"_400","500":"_500","600":"_600","700":"_700","800":"_800","900":"_900"};

function fontWeightToJs(param) {
  return _map[param];
}

function fontWeightFromJs(param) {
  return _revMap[param];
}

exports.fontWeightToJs = fontWeightToJs;
exports.fontWeightFromJs = fontWeightFromJs;
/* No side effect */
