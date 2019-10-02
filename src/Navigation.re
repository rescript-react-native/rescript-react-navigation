type t;

type navigationEventPayload = {
  .
  "action": NavigationActions.action,
  "context": string,
  "type": string,
  "state": NavigationState.t,
  "lastState": Js.Nullable.t(NavigationState.t),
};

[@bs.val] [@bs.module "react-navigation"]
external navigationContext: React.Context.t(t) = "NavigationContext";

let useNavigation = () => React.useContext(navigationContext);

[@bs.get] external state: t => NavigationState.t = "";

[@bs.send] external navigate: (t, string) => unit = "";
[@bs.send]
external navigateWithParams: (t, string, Js.t({..})) => unit = "navigate";
[@bs.send] external goBack: t => unit = "";
[@bs.send] external goBackToRoute: (t, string) => unit = "";
[@bs.send] external getParam: (t, string) => Js.nullable('a) = "";
[@bs.send] external getParamWithDefault: (t, string, 'a) => 'a = "getParam";
[@bs.send]
external addListener:
  (
    t,
    [@bs.string] [ | `didBlur | `didFocus | `willBlur | `willFocus],
    navigationEventPayload => unit
  ) =>
  EventSubscription.t =
  "addListener";

// TODO: setParams, ...
// Stack Actions
// TODO: push, replace, ...
[@bs.send] external pop: t => unit = "";
[@bs.send] external popN: (t, int) => unit = "";
[@bs.send] external popToTop: t => unit = "";
// Drawer navigator only
[@bs.send] external openDrawer: t => unit = "";
[@bs.send] external closeDrawer: t => unit = "";
[@bs.send] external toggleDrawer: t => unit = "";
