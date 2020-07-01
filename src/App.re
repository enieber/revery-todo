open Revery;
open Revery.UI;
open Revery.UI.Components;

let titleWindows = "Todo List"

let windowConfig = (app) => App.createWindow(
  app,
  titleWindows,
  ~createOptions=Config.createOptions       
);

let init = app => {
  Revery.App.initConsole();

  Timber.App.enable();
  Timber.App.setLevel(Timber.Level.perf);

  let win = windowConfig(app);

  let _update: Revery.UI.renderFunction = UI.start(win, <TodoList />);
  ();
};

App.start(init);
