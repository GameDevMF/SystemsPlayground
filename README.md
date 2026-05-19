# Systems Playground

A long-term C++ engineering playground focused on building practical systems,
improving debugging skills, and developing real software engineering habits.

This repository is part of a 12-week engineering foundation plan covering:

- Modern C++
- Data structures
- Git workflows
- Linux fundamentals
- Debugging
- Practical Python
- Modular software architecture

The goal is not to build a perfect portfolio project.

The goal is to build consistency, engineering thinking, and confidence through
small practical systems developed incrementally over time.

---

# Current Features

## Week 1
- Initial project structure
- Basic CLI application
- Header/source file separation
- Git repository setup

---

# Folder Structure

```txt
SystemsPlayground/
│
├── src/
├── include/
├── data/
├── config/
├── build/
└── README.md
```

---

# Technologies

- C++
- Git
- Command Line / Terminal
- Visual Studio

---

# Long-Term Vision

Over time this repository will evolve into a small systems-oriented toolbox
containing:

- Logging systems
- Config loaders
- Command parsers
- Save/load systems
- STL practice
- Testing infrastructure
- Serialization systems
- Utility modules

---

# Philosophy

Build more than consume.

Focus on consistency over intensity.

Learn by constructing systems, debugging mistakes, and iterating repeatedly.

---

# Development Progress

## Week 1 - Day 1 Progress

Completed:
- Initial project setup
- Git repository initialization
- Visual Studio project configuration
- Header/source file separation
- First CLI interaction system
- Basic utility functions

Concepts practiced:
- Functions
- std::string
- Input/output
- Include headers
- Modular code organization
- Git commits

## Week 1 - Day 2 Progress

Completed:
- Added vector-based activity tracking system
- Implemented menu-driven CLI workflow
- Added activity removal system
- Added duplicate activity validation
- Implemented developer diagnostics mode
- Added long activity filtering

Concepts practiced:
- std::vector
- Range-based loops
- Input validation
- Collection management
- Switch statements
- Function organization
- Defensive programming

## Week 1 - Day 3 Progress

Completed:
- Added Python scripting workspace
- Built first activity tracking script
- Implemented persistent file save/load system
- Added duplicate activity validation
- Practiced Python function decomposition

Concepts practiced:
- Python lists
- File I/O
- Exception handling
- Loops
- Functions
- Persistent data storage
- enumerate()

## Week 1 - Day 4 Progress

Completed:
- Practiced terminal-only project navigation
- Improved Git workflow familiarity
- Created and merged first feature branch
- Refactored CLI menu printing into separate function
- Added colored CLI error feedback
- Improved loop type safety using size_t
- Added activity tracking counter

Concepts practiced:
- Terminal navigation
- Git status awareness
- Branching workflows
- Merge workflows
- Basic refactoring
- Separation of concerns
- Command-line tooling
- Console styling
- Safer iteration patterns

## Week 1 - Day 5 Progress

Completed:
- Practiced breakpoint debugging in Visual Studio
- Added reusable colored console messaging system
- Added warning and error helper functions
- Implemented shortest/longest activity analysis
- Implemented average activity name length calculation
- Added centralized activity validation helper
- Practiced intentional bug investigation and debugging

Concepts practiced:
- Runtime debugging
- Breakpoints
- Refactoring
- Utility abstraction
- Edge-case awareness
- Collection analysis
- Guard clauses
- Reusable helper functions
- Basic platform-specific APIs

## Week 1 - Day 6 Progress

Completed:
- Introduced structured activity data model using structs
- Refactored vector storage from strings to Activity objects
- Added activity completion tracking system
- Updated statistics systems for structured activity data
- Expanded developer diagnostics information
- Refactored existing systems to support richer state management

Concepts practiced:
- Structs
- State management
- Refactoring
- Data modeling
- Boolean state tracking
- Collection transformations
- Incremental architecture evolution
- Runtime state mutation

## Week 1 - Day 7 Progress

Completed:
- Performed full Week 1 code cleanup pass
- Replaced magic menu values with constexpr constants
- Added reusable activity status formatting helper
- Added centralized activity index validation
- Improved text input handling using std::getline
- Expanded developer diagnostics information
- Completed Week 1 engineering retrospective

Concepts practiced:
- Refactoring
- Maintainability
- Input handling
- Code readability
- Validation layers
- Cleanup workflows
- Engineering retrospectives
- Incremental system improvement

## Week 2 - Day 1 Progress

Completed:
- Introduced ActivityManager class
- Moved activity ownership into encapsulated manager system
- Refactored global activity logic into class methods
- Introduced private activity state management
- Split class declarations and implementations into separate files
- Improved separation between application flow and system logic

Concepts practiced:
- Classes
- Encapsulation
- Public/private access
- Object ownership
- Member functions
- Header/source separation
- Refactoring toward object-oriented design

## Week 2 - Day 2 Progress

Completed:
- Added constructors to Activity data model
- Introduced constructor initialization lists
- Refactored activity creation workflow
- Added ActivityManager constructor
- Added validated user-configurable activity priorities
- Improved object lifecycle handling

Concepts practiced:
- Constructors
- Initialization lists
- Object lifecycle
- Input validation
- Data integrity
- Encapsulation
- Controlled object creation