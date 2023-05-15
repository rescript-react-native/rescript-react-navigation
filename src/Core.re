module Params = {
  type t;

  // Convert the Params to a Js.t, so you can unsafely do `##myProp`
  external asJs: t => Js.t(_) = "%identity";

  external toJson: t => Js.Json.t = "%identity";
  external unsafeGetValue: t => 'a = "%identity";
};

type params = Params.t;

type route = {
  key: string,
  name: string,
  params: option(params),
  path: option(string),
};

type navigationState = {
  key: string,
  index: int,
  routeNames: array(string),
  routes: array(route),
};

type navigation;

type screenOptionsParams = {
  navigation,
  route,
};

/*
 type screenProps = {
   navigation,
   route,
 };
 */
type screenProps = {
  .
  "navigation": navigation,
  "route": route,
};

type getIdOptions = {params};

type layout = {
  width: float,
  height: float,
};

[@bs.deriving jsConverter]
type backBehavior = [
  | `firstRoute
  | `initialRoute
  | `order
  | `history
  | `none
];

type unsubscribe = unit => unit;

// TODO
type descriptor;

type descriptors = Js.Dict.t(descriptor);

module NavigationEvent = {
  type t('data) = {
    data: 'data,
    target: option(string),
  };

  [@bs.send] external preventDefault: t('data) => unit = "preventDefault";
};

type navigationEvent('data) = NavigationEvent.t('data);

type stateEventData = {state: navigationState};

type action;

module Navigation = {
  type t = navigation;

  [@bs.send] external navigate: (t, string) => unit = "navigate";

  [@bs.send]
  external navigateWithParams: (t, string, 'params) => unit = "navigate";

  [@bs.send] external goBack: (navigation, unit) => unit = "goBack";

  [@bs.send] external reset: (navigation, navigationState) => unit = "reset";

  [@bs.send] external isFocused: (navigation, unit) => bool = "isFocused";

  [@bs.send] external dispatch: (t, action) => unit = "dispatch";

  [@bs.send] external canGoBack: (navigation, unit) => bool = "canGoBack";

  [@bs.send] external setParams: (navigation, 'params) => unit = "setParams";

  [@bs.send]
  external getParent: navigation => Js.nullable(navigation) = "getParent";

  [@bs.send]
  external getState: navigation => Js.nullable(navigationState) = "getState";

  [@bs.send]
  external addEventListener:
    (
      navigation,
      [@bs.string] [
        | `focus(navigationEvent(unit) => unit)
        | `blur(navigationEvent(unit) => unit)
        | `state(navigationEvent(stateEventData) => unit)
      ]
    ) =>
    unsubscribe =
    "addListener";
};
