-- PostgreSQL schema for PhonebookProject
CREATE TABLE IF NOT EXISTS contacts (
    id SERIAL PRIMARY KEY,
    first_name TEXT,
    last_name TEXT,
    middle_name TEXT,
    birth_date DATE,
    email TEXT,
    address TEXT
);

CREATE TABLE IF NOT EXISTS phones (
    id SERIAL PRIMARY KEY,
    contact_id INTEGER REFERENCES contacts(id) ON DELETE CASCADE,
    phone TEXT
);