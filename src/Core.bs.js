'use strict';

var Caml_option = require("rescript/lib/js/caml_option.js");

function NavigationHelpersCommon(M) {
  var navigateByKey = function (key, params, navigation) {
    var tmp = {
      key: key
    };
    if (params !== undefined) {
      tmp.params = Caml_option.valFromOption(params);
    }
    navigation.navigate(tmp);
    
  };
  var navigateByName = function (name, key, params, navigation) {
    var tmp = {
      name: name
    };
    if (key !== undefined) {
      tmp.key = key;
    }
    if (params !== undefined) {
      tmp.params = Caml_option.valFromOption(params);
    }
    navigation.navigate(tmp);
    
  };
  return {
          navigateByKey: navigateByKey,
          navigateByName: navigateByName
        };
}

function EventConsumer(M) {
  return {};
}

function NavigationScreenProp(M) {
  var navigateByKey = function (key, params, navigation) {
    var tmp = {
      key: key
    };
    if (params !== undefined) {
      tmp.params = Caml_option.valFromOption(params);
    }
    navigation.navigate(tmp);
    
  };
  var navigateByName = function (name, key, params, navigation) {
    var tmp = {
      name: name
    };
    if (key !== undefined) {
      tmp.key = key;
    }
    if (params !== undefined) {
      tmp.params = Caml_option.valFromOption(params);
    }
    navigation.navigate(tmp);
    
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
