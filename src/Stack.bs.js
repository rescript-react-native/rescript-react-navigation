'use strict';

var Interop = require("./Interop");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var Core$ReactNavigation = require("./Core.bs.js");
var Stack = require("@react-navigation/stack");

var TransitionSpec = { };

var StackNavigationScreenProp = Core$ReactNavigation.NavigationScreenProp;

function Make(M) {
  var M$1 = { };
  var include = Core$ReactNavigation.NavigationScreenProp(M$1);
  var Navigation = include;
  var t = function (prim) {
    return Interop.identity(prim[1]);
  };
  var string = function (s) {
    return Interop.identity(s);
  };
  var render = function (x) {
    return Interop.identity(x);
  };
  var HeaderTitle = {
    t: t,
    string: string,
    render: render
  };
  var t$1 = function (prim) {
    return Interop.identity(prim[1]);
  };
  var render$1 = function (x) {
    return Interop.identity(x);
  };
  var $$null = Interop.identity(null);
  var Header = {
    t: t$1,
    render: render$1,
    $$null: $$null
  };
  var stack = Stack.createStackNavigator();
  var makeProps = function (name, options, initialParams, componentOrRenderCallback, param) {
    if (componentOrRenderCallback.tag) {
      var arg = componentOrRenderCallback[0];
      var makeProps$prime = function (param, param$1, param$2) {
        return (function (param$3) {
            var param$4 = param;
            var param$5 = param$1;
            var param$6 = param$2;
            var param$7 = arg;
            var tmp = {
              name: name
            };
            if (param$4 !== undefined) {
              tmp.options = Caml_option.valFromOption(param$4);
            }
            if (param$5 !== undefined) {
              tmp.initialParams = Caml_option.valFromOption(param$5);
            }
            if (param$6 !== undefined) {
              tmp.component = Caml_option.valFromOption(param$6);
            }
            if (param$7 !== undefined) {
              tmp.children = Caml_option.valFromOption(param$7);
            }
            return tmp;
          });
      };
      if (options !== undefined) {
        var options$1 = options;
        if (initialParams !== undefined) {
          return makeProps$prime(options$1, Caml_option.some(Caml_option.valFromOption(initialParams)), undefined)(/* () */0);
        } else {
          return makeProps$prime(options$1, undefined, undefined)(/* () */0);
        }
      } else if (initialParams !== undefined) {
        return makeProps$prime(undefined, Caml_option.some(Caml_option.valFromOption(initialParams)), undefined)(/* () */0);
      } else {
        return makeProps$prime(undefined, undefined, undefined)(/* () */0);
      }
    } else {
      var func = function (param, param$1, param$2, param$3, param$4) {
        var tmp = {
          name: name
        };
        if (param !== undefined) {
          tmp.options = Caml_option.valFromOption(param);
        }
        if (param$1 !== undefined) {
          tmp.initialParams = Caml_option.valFromOption(param$1);
        }
        if (param$2 !== undefined) {
          tmp.component = Caml_option.valFromOption(param$2);
        }
        if (param$3 !== undefined) {
          tmp.children = Caml_option.valFromOption(param$3);
        }
        return tmp;
      };
      var arg$1 = componentOrRenderCallback[0];
      if (options !== undefined) {
        var options$2 = options;
        if (initialParams !== undefined) {
          var partial_arg = Caml_option.some(Caml_option.valFromOption(initialParams));
          var partial_arg$1 = options$2;
          return (function (param, param$1) {
                      return func(partial_arg$1, partial_arg, arg$1, param, param$1);
                    })(undefined, /* () */0);
        } else {
          var partial_arg$2 = options$2;
          return (function (param, param$1) {
                      return func(partial_arg$2, undefined, arg$1, param, param$1);
                    })(undefined, /* () */0);
        }
      } else if (initialParams !== undefined) {
        var partial_arg$3 = Caml_option.some(Caml_option.valFromOption(initialParams));
        return (function (param, param$1) {
                    return func(undefined, partial_arg$3, arg$1, param, param$1);
                  })(undefined, /* () */0);
      } else {
        return func(undefined, undefined, arg$1, undefined, /* () */0);
      }
    }
  };
  var make = stack.Screen;
  var $$Screen = {
    makeProps: makeProps,
    make: make
  };
  var make$1 = stack.Navigator;
  var $$Navigator = {
    make: make$1
  };
  return {
          Navigation: Navigation,
          HeaderTitle: HeaderTitle,
          Header: Header,
          stack: stack,
          $$Screen: $$Screen,
          $$Navigator: $$Navigator
        };
}

var TransitionSpecs = { };

var CardStyleInterpolators = { };

var HeaderStyleInterpolators = { };

var TransitionPresets = { };

exports.TransitionSpec = TransitionSpec;
exports.StackNavigationScreenProp = StackNavigationScreenProp;
exports.Make = Make;
exports.TransitionSpecs = TransitionSpecs;
exports.CardStyleInterpolators = CardStyleInterpolators;
exports.HeaderStyleInterpolators = HeaderStyleInterpolators;
exports.TransitionPresets = TransitionPresets;
/* ./Interop Not a pure module */
