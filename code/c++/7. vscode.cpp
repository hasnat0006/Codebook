{
  "key" : "f5", 
  "command" : "workbench.action.terminal.sendSequence", 
  "args" : {
    "text" : "g++ ${fileBasenameNoExtension}.cpp -o  ${fileBasenameNoExtension} && ./ ${fileBasenameNoExtension} <in.txt> out.txt\n "
  }
}
