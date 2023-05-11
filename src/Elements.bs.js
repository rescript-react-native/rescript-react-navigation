


var _map = {"left":"left","center":"center"};

function headerTitleAlignToJs(param) {
  return param;
}

function headerTitleAlignFromJs(param) {
  return _map[param];
}

var Header = {
  headerTitleAlignToJs: headerTitleAlignToJs,
  headerTitleAlignFromJs: headerTitleAlignFromJs
};

var HeaderBackground = {};

var HeaderBackButton = {};

export {
  Header ,
  HeaderBackground ,
  HeaderBackButton ,
  
}
/* No side effect */
