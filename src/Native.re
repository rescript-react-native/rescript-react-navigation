/*
 # Example with state persistance

 Require to have
 - @reason-react-native/storage (ReactNativeAsyncStorage)
 - reason-future

 Require to define your own

 - <RootNavigator />
 - <BootSplash />


 ```reason
 open Belt;
 open ReactNative;

 // @todo
 // <RootNavigator />
 // <Bootsplash />

 type navigationState;
 let navigationStateStorageKey = "react-navigation:state";

 [@react.component]
 let app = () => {
   let (initialStateContainer, setInitialState) = React.useState(() => None);

   React.useEffect1(
     () => {
       if (initialStateContainer->Option.isNone) {
         ReactNativeAsyncStorage.getItem(navigationStateStorageKey)
         ->FutureJs.fromPromise(error => {
             // @todo ?
             Js.log2("Restoring Navigation State: ", error);
             error;
           })
         ->Future.tap(res => {
             switch (res) {
             | Result.Ok(jsonState) =>
               switch (jsonState->Js.Null.toOption) {
               | Some(jsonState) =>
                 switch (Js.Json.parseExn(jsonState)) {
                 | state =>
                   setInitialState(_ => Some(Some(state)));
                 | exception _ =>
                   Js.log2(
                     "Restoring Navigation State: unable to decode valid json",
                     jsonState,
                   );
                   setInitialState(_ => Some(None));
                 }
               | None => setInitialState(_ => Some(None))
               };
             | Result.Error(e) =>
               Js.log2(
                 "Restoring Navigation State: unable to get json state",
                 e,
               );
               setInitialState(_ => Some(None));
             };
           })
         ->ignore;
       };
       None;
     },
     [|initialStateContainer|],
   );

   let isReady = initialStateContainer->Option.isSome;
   <>
       {initialStateContainer
        ->Option.map(initialState =>
            <Native.NavigationContainer
              ?initialState
              onStateChange={state => {
                let maybeJsonState = Js.Json.stringifyAny(state);
                switch (maybeJsonState) {
                | Some(jsonState) =>
                  AsyncStorage.setItem(navigationStateStorageKey, jsonState)
                  ->ignore
                | None => Js.log("Unable to stringify navigation state")
                };
              }}>
              <RootNavigator />
            </Native.NavigationContainer>
          )
        ->Option.getWithDefault(React.null)}
       <Bootsplash isReady />
   </>;
 };
 ```
 */

module NavigationContainer = {
  type state = Js.Json.t;
  type navigationState = state => unit;

  [@bs.module "@react-navigation/native"] [@react.component]
  external make:
    (
      ~ref: ReactNative.NativeElement.ref=?,
      ~initialState: state=?,
      ~onStateChange: navigationState=?,
      ~children: React.element
    ) =>
    React.element =
    "NavigationContainer";
};

[@bs.module "@react-navigation/native"]
external useIsFocused: unit => bool = "useIsFocused";
