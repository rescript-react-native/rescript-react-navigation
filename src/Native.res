type themeColors = {
  primary: string,
  background: string,
  card: string,
  text: string,
  border: string,
  notification: string,
}
type theme = {
  dark: bool,
  colors: themeColors,
}
@module("@react-navigation/native")
external defaultTheme: theme = "DefaultTheme"
@module("@react-navigation/native")
external darkTheme: theme = "DarkTheme"
@module("@react-navigation/native")
external useTheme: unit => theme = "useTheme"

module NavigationContainer = {
  type state = Js.Json.t
  type navigationState = state => unit

  @module("@react-navigation/native") @react.component
  external make: (
    ~ref: ReactNative.Ref.t<Core.navigation>=?,
    ~initialState: state=?,
    ~onStateChange: navigationState=?,
    ~onReady: unit => unit=?,
    ~theme: theme=?,
    ~children: React.element,
  ) => React.element = "NavigationContainer"
}

@module("@react-navigation/native")
external useNavigation: unit => Js.nullable<Core.navigation> = "useNavigation"

@module("@react-navigation/native")
external useRoute: unit => Js.nullable<Core.route> = "useRoute"

@module("@react-navigation/native")
external useIsFocused: unit => bool = "useIsFocused"

type focusCallback = unit => option<unit => unit>
@module("@react-navigation/native")
external useFocusEffect: focusCallback => unit = "useFocusEffect"

@module("@react-navigation/native")
external useScrollToTop: React.ref<'value> => unit = "useScrollToTop"

type serverContainer<'a> = {getCurrentOptions: option<'a>}
type location = {
  pathname: string,
  search: string,
}
module ServerContainer = {
  @module("@react-navigation/native") @react.component
  external make: (
    ~ref: ReactNative.Ref.t<serverContainer<'a>>=?,
    ~location: location=?,
    ~children: React.element,
  ) => React.element = "ServerContainer"
}

module CommonActions = {
  type navigateParams

  @obj
  external navigateParams: (
    ~name: string=?,
    ~key: string=?,
    ~params: 'params=?,
    unit,
  ) => navigateParams = ""

  @module("@react-navigation/native") @scope("CommonActions")
  external navigate: navigateParams => Core.action = "navigate"

  @module("@react-navigation/native") @scope("CommonActions")
  external goBack: unit => Core.action = "goBack"
}

@module("@react-navigation/native")
external useLinkTo: string => unit = "useLinkTo"

type linkPropsIn = {
  to_: string,
  action: unit => unit,
}
type linkPropsOut = {
  href: string,
  accessibilityRole: string,
  onPress: unit => unit,
}

@module("@react-navigation/native")
external useLinkProps: linkPropsIn => linkPropsOut = "useLinkProps"

type linkBuilderOut<'a> = (string, 'a) => string

@module("@react-navigation/native")
external useLinkBuilder: unit => linkBuilderOut<'a> = "useLinkBuilder"

module Link = {
  @module("@react-navigation/native") @react.component
  external make: (
    ~to_: string=?,
    ~action: unit => unit=?,
    ~children: React.element,
  ) => React.element = "Link"
}
