open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  open Style;

  let container = [padding(20)];
  let input = [];
  let button = [
    backgroundColor(Color.hex(Theme.primary)),
    padding(20),
    margin(10),
    borderRadius(5.)
  ];
  let text = [marginTop(24), color(Color.hex(Theme.darkBlue))];
  let itemTodo = [
    justifyContent(`Center),
    alignItems(`Center),
    flexDirection(`Row),
  ];
  let containerAdd = [
    justifyContent(`Center),
    alignItems(`Center),
    flexDirection(`Row),
  ];
  let outerBox = [
    width(300),
    height(200),
  ]
};

let%component make = () => {
    let%hook (todoList, setTodoList) = React.Hooks.state([]);
    let%hook (todoItem, setTodoItem) = React.Hooks.state("");

    let onUserTyping = (value, _) => setTodoItem(_ => value);
    
    let onAddItem = () => {
    switch(todoItem) {
        | "" => setTodoItem(_ => "")
        | _ => 
        setTodoList(items => [todoItem, ...items])
        setTodoItem(_ => "")
    }      
    };

    let onRemoveItem = (item) => {
    let newList = todoList 
        |> List.filter(itemBase => itemBase !== item)
    setTodoList(_ => newList);   
    }

    let todoElements =
    todoList
    |> List.map(item => (
        <View style=Styles.itemTodo>
        <Row>
        <Text text=item  style=Styles.text/>
        <Clickable style=Styles.button onClick={() => onRemoveItem(item)}>
            <Text text="x"/>
        </Clickable>
        </Row>
        </View>
    ))
    |> Brisk_reconciler.listToElement;

    <View style=Styles.container>
    <View style=Styles.containerAdd>
        <Input
        value=todoItem
        onChange=onUserTyping
        style=Styles.input
        />
        <Clickable onClick=onAddItem style=Styles.button>
        <Text text="Add" />
        </Clickable>
    </View>
    <ScrollView style=Styles.outerBox bounce={true}>
        todoElements
    </ScrollView>    
    </View>;
};
