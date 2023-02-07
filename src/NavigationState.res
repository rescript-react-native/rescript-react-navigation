type rec t = {
  index: int,
  routeName: string,
  routes: option<array<t>>,
  isDrawerOpen: bool,
}

type persistNavigationState = t => promise<unit>
type loadNavigationState = unit => promise<option<t>>
