module Params = {
  type t

  external toJson: t => Js.Json.t = "%identity"
  external unsafeGetValue: t => 'a = "%identity"
}

type params = Params.t

type rec route = {
  key: string,
  name: string,
  params: option<params>,
  path: option<string>,
}
and navigationState = {
  key: string,
  index: int,
  routeNames: array<string>,
  routes: array<route>,
}

type navigation

type screenOptionsParams = {navigation: navigation, route: route}

type screenProps = {navigation: navigation, route: route}

type getIdOptions = {params: params}

type layout = {width: float, height: float}

type backBehavior = [#firstRoute | #initialRoute | #order | #history | #none]

type unsubscribe = unit => unit

// TODO
type descriptor

type descriptors = Js.Dict.t<descriptor>

module NavigationEvent = {
  type t<'data> = {
    data: 'data,
    target: option<string>,
  }

  @send external preventDefault: t<'data> => unit = "preventDefault"
}

type navigationEvent<'data> = NavigationEvent.t<'data>

type stateEventData = {state: navigationState}

type action

type layoutNavigatorParams = {
  state: navigationState,
  navigation: navigation,
  descriptors: descriptors,
  children: React.element,
}

module Navigation = {
  type t = navigation

  @send external navigate: (t, string) => unit = "navigate"
  @send
  external navigateWithParams: (t, string, 'params) => unit = "navigate"

  @send external navigateDeprecated: (t, string) => unit = "navigateDeprecated"
  @send
  external navigateDeprecatedWithParams: (t, string, 'params) => unit = "navigateDeprecated"

  @send external goBack: (navigation, unit) => unit = "goBack"

  @send
  external reset: (navigation, navigationState) => unit = "reset"

  @send external preload: (t, string) => unit = "preload"
  @send
  external preloadWithParams: (t, string, 'params) => unit = "preload"

  @send external isFocused: (navigation, unit) => bool = "isFocused"

  @send
  external dispatch: (t, action) => unit = "dispatch"

  @send external canGoBack: (navigation, unit) => bool = "canGoBack"

  @send external setParams: (navigation, 'params) => unit = "setParams"

  @send
  external getParent: navigation => Js.nullable<navigation> = "getParent"

  @send
  external getState: navigation => Js.nullable<navigationState> = "getState"

  @send
  external addEventListener: (
    navigation,
    @string
    [
      | #focus(navigationEvent<unit> => unit)
      | #blur(navigationEvent<unit> => unit)
      | #state(navigationEvent<stateEventData> => unit)
    ],
  ) => unsubscribe = "addListener"
}
