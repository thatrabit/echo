#include "instrument.hpp"

Instrument::Instrument(QObject* parent) : QObject(parent) {
}

Instrument::Instrument(const QString& symbol, QObject* parent) : QObject(parent), m_symbol(symbol) {
}

QString Instrument::symbol() const {
    return m_symbol;
}

void Instrument::updateSymbol(const QString& symbol) {
    if (symbol == m_symbol)
        return;
    m_symbol = symbol;
    emit symbolUpdated();
}
