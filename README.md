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

## Week 2
- Object-oriented activity management system
- Activity lifecycle tracking
- Strongly typed enums
- Persistent save/load system
- Activity sorting and filtering
- Defensive file parsing
- Save file versioning
- Input validation utilities
- Developer diagnostics tools
- Case-insensitive sorting
- Modular serialization system

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
- STL
- Git
- Command Line / Terminal
- Visual Studio
- File I/O

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
- Debugging utilities
- Data processing systems
- Small engine-style subsystems

---

# Philosophy

Build more than consume.

Focus on consistency over intensity.

Learn by constructing systems, debugging mistakes, and iterating repeatedly.

Prefer clarity and maintainability over unnecessary complexity.

Treat every small system as deliberate engineering practice.

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

---

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

---

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

---

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

---

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

---

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

---

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

---

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

---

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

---

## Week 2 - Day 3 Progress

Completed:
- Reduced unnecessary object copying
- Introduced const references in interfaces
- Added const member functions
- Refactored reusable activity print helper
- Added high-priority activity filtering
- Improved interface safety and readability

Concepts practiced:
- Const correctness
- References
- Const references
- Interface design
- Read-only access
- API safety
- Avoiding unnecessary copies
- Reusable formatting systems

---

## Week 2 - Day 4 Progress

Completed:
- Replaced boolean activity completion tracking with ActivityStatus enum class
- Added PriorityLevel enum class for stronger priority modeling
- Added activity lifecycle states:
  - Todo
  - In Progress
  - Completed
- Implemented activity state transitions
- Added filtering by activity status
- Added reusable status and priority string helpers
- Improved input validation using reusable parsing utilities
- Added TryToGetInputNumber helper for safer integer conversion
- Refactored developer diagnostics into ActivityManager

Concepts practiced:
- Enum classes
- Strong typing
- State machines
- State transitions
- Explicit type conversion
- Reusable utility functions
- Input validation
- Output parameters
- Encapsulation
- Reusable filtering systems
- Centralized formatting logic
- Safer console input handling

Key learning:
- Good data models simplify system logic
- Reusable utility functions reduce duplication
- Robust input handling is essential for stable software

---

## Week 2 - Day 5 Progress

Completed:
- Added activity saving system
- Added activity loading system
- Implemented file persistence
- Added automatic loading on startup
- Added automatic saving after activity changes
- Introduced activity serialization and deserialization

Concepts practiced:
- File I/O
- std::ofstream
- std::ifstream
- Persistence systems
- Serialization
- Deserialization
- Save/load workflows
- Application lifecycle management
- Parsing structured data
- Data reconstruction
- Basic serialization format design
- Persistent application state
- File parsing and reconstruction
- Defensive file handling

---

## Week 2 - Day 6 Progress

Completed:
- Added activity sorting systems
- Added custom comparison logic
- Improved save file robustness
- Added corrupted data handling
- Refactored repeated save path usage
- Expanded activity filtering systems
- Added case-insensitive sorting support
- Added save file versioning
- Added defensive deserialization checks
- Improved invalid data recovery handling

Concepts practiced:
- std::sort
- STL algorithms
- Custom comparators
- Data ordering
- Filtering systems
- Defensive programming
- Save validation
- Maintainability improvements
- Cleaner architecture organization
- Case-insensitive sorting
- Multi-criteria sorting
- Save format versioning
- Corrupted save recovery
- Defensive deserialization
- STL algorithm usage

---

## Week 2 - Day 7 Progress

Completed:
- Performed Week 2 architecture cleanup
- Refactored serialization/version handling
- Improved save compatibility validation
- Reduced duplicated logic across systems
- Improved naming consistency
- Refined sorting and utility systems
- Improved defensive loading workflow
- Reviewed overall code maintainability
- Continued cleanup of object-oriented architecture

Concepts practiced:
- Architecture cleanup
- Refactoring workflows
- Naming consistency
- Defensive loading systems
- Maintainability improvements
- Serialization validation
- Incremental software evolution
- Codebase organization
- System robustness
- Long-term project maintainability

---

## Week 3 - Day 1 Progress

Completed:
- Added centralized command processing system
- Introduced reusable command parsing workflow
- Refactored CLI interaction into command-based architecture
- Added clear command for activity reset
- Improved input routing through ProcessCommand
- Added reusable command retrieval helper
- Improved activity index validation flow
- Added safer startup save validation pipeline
- Refactored save parsing into dedicated helper functions
- Added reusable activity deserialization helper
- Improved corrupted save handling
- Refactored version validation into dedicated function
- Introduced modern C++ starts_with command parsing
- Reduced duplicated command logic

Concepts practiced:
- Command systems
- CLI architecture
- Parsing workflows
- Function decomposition
- Responsibility separation
- Centralized input handling
- Serialization pipelines
- Deserialization
- Defensive file parsing
- Validation systems
- std::sort
- Lambda functions
- Modern C++ string utilities
- starts_with
- Encapsulation
- Reusable parsing helpers
- Incremental architecture refactoring
- Cleaner system organization