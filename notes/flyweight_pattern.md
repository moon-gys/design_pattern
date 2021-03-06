## 享元模式
<https://design-patterns.readthedocs.io/zh_CN/latest/structural_patterns/flyweight.html>

### 动机

当对象数量太多时，将导致运行代价过高，带来性能下降等问题。
  - 享元模式正是为解决这一类问题而诞生的。享元模式通过共享技术实现相同或相似对象的重用。
  - 在享元模式中可以共享的相同内容称为内部状态(IntrinsicState)，而那些需要外部环境来设置的不能共享的内容称为外部状态(Extrinsic State)，由于区分了内部状态和外部状态，因此可以通过设置不同的外部状态使得相同的对象可以具有一些不同的特征，而相同的内部状态是可以共享的。
  - 在享元模式中通常会出现工厂模式，需要创建一个享元工厂来负责维护一个享元池(Flyweight Pool)用于存储具有相同内部状态的享元对象。
  - 在享元模式中共享的是享元对象的内部状态，外部状态需要通过环境来设置。在实际使用中，能够共享的内部状态是有限的，因此享元对象一般都设计为较小的对象，它所包含的内部状态较少，这种对象也称为细粒度对象。享元模式的目的就是使用共享技术来实现大量细粒度对象的复用。
 
### 模式结构

享元模式包含如下角色：

- Flyweight: 抽象享元类，描述一个接口，通过这个接口 Flyweight 可以接受并作用于外部状态。
- ConcreteFlyweight: 具体享元类，实现 Flyweight 接口，并为内部状态增加存储空间。该对象必须是可共享的。它所存储的状态必须是内部的，即必须独立于对象的场景。
- UnsharedConcreteFlyweight: 非共享具体享元类，并非所有的 Flyweight 子类都需要被共享。Flyweight 接口使共享成为可能，但它并不强制共享。
- FlyweightFactory: 享元工厂类
  - 创建并管理 Flyweight 对象。
  - 确保合理地共享 Flyweight。
 - Client
  - 维持一个对 Flyweight 的引用。
  - 计算或存储 Flyweight 的外部状态。
  
 ### UML
 
 <img src="../images/flyweight_architecture.png" heigth=299 length=300>
 
  
 <img src="../images/flyweight_object.png" heigth=299 length=300>
