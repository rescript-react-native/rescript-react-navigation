module NavigationNativeContainer = {
  //TODO
  type initialState;
  type navigationState;

  [@bs.module "@react-navigation/native"] [@react.component]
  external make:
    (
      ~initialState: initialState=?,
      ~onStateChange: navigationState=?,
      ~children: React.element
    ) =>
    React.element =
    "NavigationNativeContainer";
};
