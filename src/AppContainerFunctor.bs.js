'use strict';

var ReactNavigation = require("react-navigation");

function Make(S) {
  var make = ReactNavigation.createAppContainer(S.navigator);
  return {
          make: make
        };
}

exports.Make = Make;
/* react-navigation Not a pure module */
