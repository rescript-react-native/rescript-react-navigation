type route('params) = {
  key: string,
  name: string,
  params: option('params),
  state: option(navigationState('params)),
}
and navigationState('params) = {
  key: string,
  index: int,
  routeNames: array(string),
  routes: array(route('params)),
};

type navigation;

module NavigationHelpersCommon = (M: {type params;}) => {
  type nonrec route = route(M.params);
  [@bs.send]
  external dispatch: (navigation, NavigationActions.action) => unit =
    "dispatch";

  [@bs.send] external navigate: (navigation, string) => unit = "navigate";
  [@bs.send]
  external navigateWithParams: (navigation, string, M.params) => unit =
    "navigate";

  type navigationParams;

  [@bs.obj]
  external navigateByKeyParams:
    (~key: string, ~params: M.params=?, unit) => navigationParams =
    "";

  [@bs.obj]
  external navigateByNameParams:
    (~name: string, ~key: string=?, ~params: M.params=?, unit) =>
    navigationParams =
    "";

  [@bs.send] external navigateBy: navigationParams => unit = "navigate";

  let navigateByKey = (~key: string, ~params: option(M.params)=?, _) =>
    navigateBy(navigateByKeyParams(~key, ~params?, ()));

  let navigateByName =
      (
        ~name: string,
        ~key: option(string)=?,
        ~params: option(M.params)=?,
        _,
      ) =>
    navigateBy(navigateByNameParams(~name, ~key?, ~params?, ()));

  [@bs.send] external replace: (navigation, string) => unit = "replace";
  [@bs.send]
  external replaceWithParams: (navigation, string, M.params) => unit =
    "replace";

  [@bs.send]
  external reset: (navigation, navigationState(M.params)) => unit = "reset";

  [@bs.send]
  external resetRoot: (navigation, navigationState(M.params)) => unit =
    "resetRoot";

  [@bs.send] external goBack: (navigation, unit) => unit = "goBack";
  [@bs.send] external isFocused: (navigation, unit) => bool = "isFocused";
  [@bs.send] external canGoBack: (navigation, unit) => bool = "canGoBack";
};

module EventConsumer = (M: {type params;}) => {
  type eventListenerOptions('data) = {
    [@bs.as "type"]
    type_: string,
    defaultPrevented: bool,
    [@bs.meth]
    preventDefault: unit => unit,
    data: option('data),
  };
  type eventListenerCallback('data) = eventListenerOptions('data) => unit;

  type unsubscribe = unit => unit;

  [@bs.send]
  external addListener:
    (
      navigation,
      [@bs.string] [ | `focus | `blur | `tabPress],
      eventListenerCallback('data)
    ) =>
    unsubscribe =
    "addListener";
  [@bs.send]
  external removeListener:
    (
      navigation,
      [@bs.string] [ | `focus | `blur | `tabPress],
      eventListenerCallback('data)
    ) =>
    unsubscribe =
    "removeListener";
};

module NavigationScreenProp = (M: {
                                 type params;
                                 type options;
                               }) => {
  include NavigationHelpersCommon(M);
  include EventConsumer(M);

  [@bs.send] external setParams: (navigation, M.params) => unit = "setParams";
  [@bs.send]
  external setOptions: (navigation, M.options) => unit = "setOptions";

  [@bs.send]
  external isFirstRouteInParent: (navigation, unit) => bool =
    "isFirstRouteInParent";

  [@bs.send]
  external dangerouslyGetParent: navigation => Js.nullable(navigation) =
    "dangerouslyGetParent";
};
