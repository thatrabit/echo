#include "instrument.hpp"

Instrument::Instrument(QObject* parent) : QObject(parent), m_symbol("NULL") {
}

Instrument::Instrument(const QString& symbol, QObject* parent) : QObject(parent), m_symbol(symbol) {
}

Instrument::~Instrument() {
}

QString Instrument::symbol() const {
    return m_symbol;
}
