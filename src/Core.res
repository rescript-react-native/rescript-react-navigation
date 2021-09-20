type rec route<'params> = {
  key: string,
  name: string,
  params: option<'params>,
  path: option<string>,
}
and navigationState<'params> = {
  key: string,
  index: int,
  routeNames: array<string>,
  routes: array<route<'params>>,
}

type navigation

module NavigationHelpersCommon = (
  M: {
    type params
  },
) => {
  type route = route<M.params>
  @send
  external dispatch: (navigation, NavigationActions.action) => unit = "dispatch"

  @send external navigate: (navigation, string) => unit = "navigate"
  @send
  external navigateWithParams: (navigation, string, M.params) => unit = "navigate"

  type navigationParams

  @obj
  external navigateByKeyParams: (
    ~key: string,
    ~params: M.params=?,
    ~merge: bool=?,
    unit,
  ) => navigationParams = ""

  @obj
  external navigateByNameParams: (
    ~name: string,
    ~key: string=?,
    ~params: M.params=?,
    ~merge: bool=?,
    unit,
  ) => navigationParams = ""

  @send external navigateBy: (navigation, navigationParams) => unit = "navigate"

  let navigateByKey = (
    ~key: string,
    ~params: option<M.params>=?,
    ~merge: option<bool>=?,
    navigation,
  ) => navigateBy(navigation, navigateByKeyParams(~key, ~params?, ~merge?, ()))

  let navigateByName = (
    ~name: string,
    ~key: option<string>=?,
    ~params: option<M.params>=?,
    ~merge: option<bool>=?,
    navigation,
  ) => navigateBy(navigation, navigateByNameParams(~name, ~key?, ~params?, ~merge?, ()))

  @send external replace: (navigation, string) => unit = "replace"
  @send
  external replaceWithParams: (navigation, string, M.params) => unit = "replace"

  @send
  external reset: (navigation, navigationState<M.params>) => unit = "reset"

  @send
  external resetRoot: (navigation, navigationState<M.params>) => unit = "resetRoot"

  @send external goBack: (navigation, unit) => unit = "goBack"
  @send external isFocused: (navigation, unit) => bool = "isFocused"
  @send external canGoBack: (navigation, unit) => bool = "canGoBack"
}

module EventConsumer = (
  M: {
    type params
  },
) => {
  type eventListenerOptions<'data> = {
    @as("type")
    type_: string,
    defaultPrevented: bool,
    preventDefault: unit => unit,
    data: option<'data>,
  }
  type eventListenerCallback<'data> = eventListenerOptions<'data> => unit

  type unsubscribe = unit => unit

  @send
  external addListener: (
    navigation,
    [#focus | #blur | #tabPress],
    eventListenerCallback<'data>,
  ) => unsubscribe = "addListener"
  @send
  external removeListener: (
    navigation,
    [#focus | #blur | #tabPress],
    eventListenerCallback<'data>,
  ) => unsubscribe = "removeListener"
}

module NavigationScreenProp = (
  M: {
    type params
    type options
  },
) => {
  include NavigationHelpersCommon(M)
  include EventConsumer(M)

  @send external setParams: (navigation, M.params) => unit = "setParams"
  @send
  external setOptions: (navigation, M.options) => unit = "setOptions"

  @send
  external isFirstRouteInParent: (navigation, unit) => bool = "isFirstRouteInParent"

  @send
  external getParent: navigation => Js.nullable<navigation> = "getParent"

  @send
  external getState: navigation => Js.nullable<navigationState<'params>> = "getState"
}
