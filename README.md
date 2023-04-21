# `reason-react-navigation`

# Notes for this qwickshifts port to ReasonML

This was done using these dependnecies:

```
  "devDependencies": {
    "bs-platform": "^8.2.0",
    "husky": "^4.0.0",
    "lint-staged": "^10.0.0",
    "npmpub": "^5.0.0",
    "prettier": "^2.0.0",
    "reason-react": "^0.9.1",
    "reason-react-native": "^0.64.0"
  },
```

The reason for these older/deprecated deps is this port is being done for compatibility with an older project,
and also because it's not currently possible to do this easily with bs-platform combined with the newer version
of `reason-react`, which is built with `dune`.

There is also not a newer version of `reason-react-native` - the newer version of this is now in `rescript`.

## Usage notes

1. Use `npm install --legacy-peer-deps` to avoid an incompatibility issue with `bs-platform`/`reason-react`/`reason-react-native`
2. Need to set up an ocaml `4.06.1` environment (can be done with `opam switch create 4.06.1`)
3. LSP tools should work with `opam install ocaml-lsp-server dot-merlin-reader` - not sure what else needs to be done, as mine didn't require additional setup
4. Use these commands for building/etc.:
   - `npm run clean`
   - `npm run build`
   - `npm run watch`

## Port Status

The code is ported and compiling, but I'm not sure if it works correctly at this point.

There are a couple interesting things going on with the `Interop` module and some module unpacking in a few of the modules.

There were a lot of `#` string style polymorphic variants in the Rescript code. I changed these to normal polymorphic variants in the Reason code, but we might need to do something to make them convert to strings in the JS code.

---

# Below are the original README contents from rescript-react-navigation

[![Build Status](https://github.com/rescript-react-native/rescript-react-navigation/workflows/Build/badge.svg)](https://github.com/rescript-react-native/rescript-react-navigation/actions)
[![Version](https://img.shields.io/npm/v/rescript-react-navigation.svg)](https://www.npmjs.com/rescript-react-navigation)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`react-navigation`](https://github.com/react-navigation/react-navigation).

Exposed as `ReactNavigation` module.

`rescript-react-navigation` X.y.\* means it's compatible with `react-navigation`
X.y.\*

## Status

⚠️ Work in progress. These bindings are used successfully in several apps, but
are not complete yet and still subject to change.

## Installation

When
[`react-navigation`](https://github.com/react-navigation/react-navigation) is
properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install rescript-react-navigation
# or
yarn add rescript-react-navigation
```

`rescript-react-navigation` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "rescript-react-navigation"
  ],
  //...
}
```

## Example

See <./src/Example.re>

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

## Contribute

Read the [contribution guidelines](https://github.com/rescript-react-native/.github/blob/master/CONTRIBUTING.md) before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/rescript-react-native/.github/blob/master/CODE_OF_CONDUCT.md) so that you can understand what
actions will and will not be tolerated.
