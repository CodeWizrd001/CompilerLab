
// Generated from modelica.g4 by ANTLR 4.7.2


#include "modelicaListener.h"

#include "modelicaParser.h"


using namespace antlrcpp;
using namespace antlr4;

modelicaParser::modelicaParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

modelicaParser::~modelicaParser() {
  delete _interpreter;
}

std::string modelicaParser::getGrammarFileName() const {
  return "modelica.g4";
}

const std::vector<std::string>& modelicaParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& modelicaParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

modelicaParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<modelicaParser::ExprContext *> modelicaParser::ProgContext::expr() {
  return getRuleContexts<modelicaParser::ExprContext>();
}

modelicaParser::ExprContext* modelicaParser::ProgContext::expr(size_t i) {
  return getRuleContext<modelicaParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> modelicaParser::ProgContext::NEWLINE() {
  return getTokens(modelicaParser::NEWLINE);
}

tree::TerminalNode* modelicaParser::ProgContext::NEWLINE(size_t i) {
  return getToken(modelicaParser::NEWLINE, i);
}


size_t modelicaParser::ProgContext::getRuleIndex() const {
  return modelicaParser::RuleProg;
}

void modelicaParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void modelicaParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}

modelicaParser::ProgContext* modelicaParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, modelicaParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(9);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == modelicaParser::T__4

    || _la == modelicaParser::INT) {
      setState(4);
      expr(0);
      setState(5);
      match(modelicaParser::NEWLINE);
      setState(11);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

modelicaParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* modelicaParser::ExprContext::INT() {
  return getToken(modelicaParser::INT, 0);
}

std::vector<modelicaParser::ExprContext *> modelicaParser::ExprContext::expr() {
  return getRuleContexts<modelicaParser::ExprContext>();
}

modelicaParser::ExprContext* modelicaParser::ExprContext::expr(size_t i) {
  return getRuleContext<modelicaParser::ExprContext>(i);
}


size_t modelicaParser::ExprContext::getRuleIndex() const {
  return modelicaParser::RuleExpr;
}

void modelicaParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void modelicaParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<modelicaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


modelicaParser::ExprContext* modelicaParser::expr() {
   return expr(0);
}

modelicaParser::ExprContext* modelicaParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  modelicaParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  modelicaParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, modelicaParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(18);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case modelicaParser::INT: {
        setState(13);
        match(modelicaParser::INT);
        break;
      }

      case modelicaParser::T__4: {
        setState(14);
        match(modelicaParser::T__4);
        setState(15);
        expr(0);
        setState(16);
        match(modelicaParser::T__5);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(28);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(26);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(20);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(21);
          _la = _input->LA(1);
          if (!(_la == modelicaParser::T__0

          || _la == modelicaParser::T__1)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(22);
          expr(5);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(23);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(24);
          _la = _input->LA(1);
          if (!(_la == modelicaParser::T__2

          || _la == modelicaParser::T__3)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(25);
          expr(4);
          break;
        }

        } 
      }
      setState(30);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool modelicaParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool modelicaParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> modelicaParser::_decisionToDFA;
atn::PredictionContextCache modelicaParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN modelicaParser::_atn;
std::vector<uint16_t> modelicaParser::_serializedATN;

std::vector<std::string> modelicaParser::_ruleNames = {
  "prog", "expr"
};

std::vector<std::string> modelicaParser::_literalNames = {
  "", "'*'", "'/'", "'+'", "'-'", "'('", "')'"
};

std::vector<std::string> modelicaParser::_symbolicNames = {
  "", "", "", "", "", "", "", "NEWLINE", "INT"
};

dfa::Vocabulary modelicaParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> modelicaParser::_tokenNames;

modelicaParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xa, 0x22, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0xa, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xd, 0xb, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x15, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x7, 0x3, 0x1d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x20, 0xb, 0x3, 
    0x3, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 0x4, 0x2, 0x4, 0x3, 0x2, 0x3, 0x4, 
    0x3, 0x2, 0x5, 0x6, 0x2, 0x23, 0x2, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4, 0x14, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x7, 0x5, 0x4, 0x3, 0x2, 0x7, 0x8, 0x7, 0x9, 
    0x2, 0x2, 0x8, 0xa, 0x3, 0x2, 0x2, 0x2, 0x9, 0x6, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0xd, 0x3, 0x2, 0x2, 0x2, 0xb, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0x3, 0x3, 0x2, 0x2, 0x2, 0xd, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xf, 0x8, 0x3, 0x1, 0x2, 0xf, 0x15, 0x7, 0xa, 0x2, 0x2, 
    0x10, 0x11, 0x7, 0x7, 0x2, 0x2, 0x11, 0x12, 0x5, 0x4, 0x3, 0x2, 0x12, 
    0x13, 0x7, 0x8, 0x2, 0x2, 0x13, 0x15, 0x3, 0x2, 0x2, 0x2, 0x14, 0xe, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x10, 0x3, 0x2, 0x2, 0x2, 0x15, 0x1e, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x17, 0xc, 0x6, 0x2, 0x2, 0x17, 0x18, 0x9, 0x2, 
    0x2, 0x2, 0x18, 0x1d, 0x5, 0x4, 0x3, 0x7, 0x19, 0x1a, 0xc, 0x5, 0x2, 
    0x2, 0x1a, 0x1b, 0x9, 0x3, 0x2, 0x2, 0x1b, 0x1d, 0x5, 0x4, 0x3, 0x6, 
    0x1c, 0x16, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1d, 
    0x20, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x1f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1e, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0xb, 0x14, 0x1c, 0x1e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

modelicaParser::Initializer modelicaParser::_init;
