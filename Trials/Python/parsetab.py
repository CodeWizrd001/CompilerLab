
# parsetab.py
# This file is automatically generated. Do not edit.
# pylint: disable=W,C,R
_tabversion = '3.10'

_lr_method = 'LALR'

_lr_signature = 'leftOPleftOP2BEGIN END ENDLINE EQ ID LPAREN NEWLINE NUM OP OP2 READ RPAREN SEMI WRITEpgm  : BEGIN Slist END SEMI\n            | BEGIN END SEMI Slist : Slist Stmt\n            | Stmt NEWLINE\n            | Stmt Stmt : Input\n            | Output\n            | Asgmt Input : READ LPAREN ID RPAREN SEMIOutput : WRITE LPAREN E RPAREN SEMIAsgmt : ID EQ E SEMIE    : E OP2 E \n            | E OP E \n            | ID '
    
_lr_action_items = {'BEGIN':([0,],[2,]),'$end':([1,14,19,],[0,-2,-1,]),'END':([2,3,5,6,7,8,13,15,25,29,32,],[4,12,-5,-6,-7,-8,-3,-4,-11,-9,-10,]),'READ':([2,3,5,6,7,8,13,15,25,29,32,],[9,9,-5,-6,-7,-8,-3,-4,-11,-9,-10,]),'WRITE':([2,3,5,6,7,8,13,15,25,29,32,],[11,11,-5,-6,-7,-8,-3,-4,-11,-9,-10,]),'ID':([2,3,5,6,7,8,13,15,16,17,18,25,26,27,29,32,],[10,10,-5,-6,-7,-8,-3,-4,20,21,21,-11,21,21,-9,-10,]),'SEMI':([4,12,21,22,24,28,30,31,],[14,19,-14,25,29,32,-12,-13,]),'NEWLINE':([5,6,7,8,25,29,32,],[15,-6,-7,-8,-11,-9,-10,]),'LPAREN':([9,11,],[16,18,]),'EQ':([10,],[17,]),'RPAREN':([20,21,23,30,31,],[24,-14,28,-12,-13,]),'OP2':([21,22,23,30,31,],[-14,26,26,-12,26,]),'OP':([21,22,23,30,31,],[-14,27,27,-12,-13,]),}

_lr_action = {}
for _k, _v in _lr_action_items.items():
   for _x,_y in zip(_v[0],_v[1]):
      if not _x in _lr_action:  _lr_action[_x] = {}
      _lr_action[_x][_k] = _y
del _lr_action_items

_lr_goto_items = {'pgm':([0,],[1,]),'Slist':([2,],[3,]),'Stmt':([2,3,],[5,13,]),'Input':([2,3,],[6,6,]),'Output':([2,3,],[7,7,]),'Asgmt':([2,3,],[8,8,]),'E':([17,18,26,27,],[22,23,30,31,]),}

_lr_goto = {}
for _k, _v in _lr_goto_items.items():
   for _x, _y in zip(_v[0], _v[1]):
       if not _x in _lr_goto: _lr_goto[_x] = {}
       _lr_goto[_x][_k] = _y
del _lr_goto_items
_lr_productions = [
  ("S' -> pgm","S'",1,None,None,None),
  ('pgm -> BEGIN Slist END SEMI','pgm',4,'p_prg','lexer.py',105),
  ('pgm -> BEGIN END SEMI','pgm',3,'p_prg','lexer.py',106),
  ('Slist -> Slist Stmt','Slist',2,'p_Slist','lexer.py',111),
  ('Slist -> Stmt NEWLINE','Slist',2,'p_Slist','lexer.py',112),
  ('Slist -> Stmt','Slist',1,'p_Slist','lexer.py',113),
  ('Stmt -> Input','Stmt',1,'p_stmt','lexer.py',124),
  ('Stmt -> Output','Stmt',1,'p_stmt','lexer.py',125),
  ('Stmt -> Asgmt','Stmt',1,'p_stmt','lexer.py',126),
  ('Input -> READ LPAREN ID RPAREN SEMI','Input',5,'p_input','lexer.py',132),
  ('Output -> WRITE LPAREN E RPAREN SEMI','Output',5,'p_output','lexer.py',139),
  ('Asgmt -> ID EQ E SEMI','Asgmt',4,'p_asgmt','lexer.py',146),
  ('E -> E OP2 E','E',3,'p_E','lexer.py',159),
  ('E -> E OP E','E',3,'p_E','lexer.py',160),
  ('E -> ID','E',1,'p_E','lexer.py',161),
]