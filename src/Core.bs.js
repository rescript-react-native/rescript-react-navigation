'use strict';

var Caml_option = require("bs-platform/lib/js/caml_option.js");

function NavigationHelpersCommon(M) {
  var navigateByKey = function (key, params, unit) {
    var tmp = {
      key: key
    };
    if (params !== undefined) {
      tmp.params = Caml_option.valFromOption(params);
    }
    tmp.navigate();
    return /* () */0;
  };
  var navigateByName = function (name, key, params, unit) {
    var tmp = {
      name: name
    };
    if (key !== undefined) {
      tmp.key = Caml_option.valFromOption(key);
    }
    if (params !== undefined) {
      tmp.params = Caml_option.valFromOption(params);
    }
    tmp.navigate();
    return /* () */0;
  };
  return {
          navigateByKey: navigateByKey,
          navigateByName: navigateByName
        };
}

function EventConsumer(M) {
  return { };
}

function NavigationScreenProp(M) {
  var navigateByKey = function (key, params, unit) {
    var tmp = {
      key: key
    };
    if (params !== undefined) {
      tmp.params = Caml_option.valFromOption(params);
    }
    tmp.navigate();
    return /* () */0;
  };
  var navigateByName = function (name, key, params, unit) {
    var tmp = {
      name: name
    };
    if (key !== undefined) {
      tmp.key = Caml_option.valFromOption(key);
    }
    if (params !== undefined) {
      tmp.params = Caml_option.valFromOption(params);
    }
    tmp.navigate();
    return /* () */0;
  };
  return {
          navigateByKey: navigateByKey,
          navigateByName: navigateByName
        };
}

exports.NavigationHelpersCommon = NavigationHelpersCommon;
exports.EventConsumer = EventConsumer;
exports.NavigationScreenProp = NavigationScreenProp;
/* No side effect */
