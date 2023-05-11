type themeColors = {
  primary: string,
  background: string,
  card: string,
  text: string,
  border: string,
  notification: string,
};

type theme = {
  dark: bool,
  colors: themeColors,
};

[@bs.module "@react-navigation/native"]
external defaultTheme: theme = "DefaultTheme"

[@bs.module "@react-navigation/native"]
external darkTheme: theme = "DarkTheme"

[@bs.module "@react-navigation/native"]
external useTheme: unit => theme = "useTheme"

module NavigationContainer = {
  type state = Js.Json.t;
  type navigationState = state => unit;

  [@react.component] [@bs.module "@react-navigation/native"]
  external make: (
    ~ref: ReactNative.Ref.t(Core.navigation)=?,
    ~initialState: state=?,
    ~onStateChange: navigationState=?,
    ~onReady: unit => unit=?,
    ~theme: theme=?,
    ~children: React.element,
  ) => React.element = "NavigationContainer"
};

[@bs.module "@react-navigation/native"]
external useNavigation: unit => Js.nullable(Core.navigation) = "useNavigation";

[@bs.module "@react-navigation/native"]
external useRoute: unit => Js.nullable(Core.route) = "useRoute";

[@bs.module "@react-navigation/native"]
external useIsFocused: unit => bool = "useIsFocused";

type focusCallback = unit => option(unit => unit);

[@bs.module "@react-navigation/native"]
external useFocusEffect: focusCallback => unit = "useFocusEffect"

[@bs.module "@react-navigation/native"]
external useScrollToTop: React.ref('value) => unit = "useScrollToTop";

type serverContainer('a) = {getCurrentOptions: option('a)};

type location = {
  pathname: string,
  search: string,
};

module ServerContainer = {
  [@bs.module "@react-navigation/native"] [@react.component]
  external make: (
    ~ref: ReactNative.Ref.t(serverContainer('a))=?,
    ~location: location=?,
    ~children: React.element,
  ) => React.element = "ServerContainer"
}

module CommonActions = {
  type navigateParams;

  [@bs.obj]
  external navigateParams: (
    ~name: string=?,
    ~key: string=?,
    ~params: 'params=?,
    unit,
  ) => navigateParams = ""

  [@bs.module "@react-navigation/native"] [@bs.scope "CommonActions"]
  external navigate: navigateParams => Core.action = "navigate";

  [@bs.module "@react-navigation/native"] [@bs.scope "CommonActions"]
  external goBack: unit => Core.action = "goBack";
};

[@bs.module "@react-navigation/native"]
external useLinkTo: string => unit = "useLinkTo";

type linkPropsIn = {
  to_: string,
  action: unit => unit,
};

type linkPropsOut = {
  href: string,
  accessibilityRole: string,
  onPress: unit => unit,
};

[@bs.module "@react-navigation/native"]
external useLinkProps: linkPropsIn => linkPropsOut = "useLinkProps";

type linkBuilderOut('a) = (string, 'a) => string;

[@bs.module "@react-navigation/native"]
external useLinkBuilder: unit => linkBuilderOut('a) = "useLinkBuilder";

module Link = {
  [@bs.module "@react-navigation/native"] [@react.component]
  external make: (
    ~to_: string=?,
    ~action: unit => unit=?,
    ~children: React.element,
  ) => React.element = "Link"
}
